# sql - cheat sheet

### Show functions that exist in sql

show functions

### Temp view

```sql
create or replace temp view nome_da_view as    select        col1, col2    from table1    where condition1
```

Then:
```sql
select * from nome_da_view
```