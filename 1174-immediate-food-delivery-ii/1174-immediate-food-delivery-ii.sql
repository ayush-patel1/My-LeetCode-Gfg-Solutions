select 
round(
    avg(d.order_date = d.customer_pref_delivery_date) * 100, 
    2
) as immediate_percentage
from Delivery d
join (
    select customer_id, min(order_date) as first_order_date
    from Delivery
    group by customer_id
) t
on d.customer_id = t.customer_id 
and d.order_date = t.first_order_date;