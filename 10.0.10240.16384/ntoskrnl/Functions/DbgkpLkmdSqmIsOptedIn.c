// DbgkpLkmdSqmIsOptedIn 
 
BOOL DbgkpLkmdSqmIsOptedIn()
{
  int v1; // [sp+4Ch] [bp-24h]
  int v2; // [sp+50h] [bp-20h]
  int v3; // [sp+54h] [bp-1Ch]

  if ( ZwOpenKey() >= 0 )
  {
    if ( ZwQueryValueKey() >= 0 && v1 == 4 && v2 == 4 )
      goto LABEL_5;
    ZwClose();
  }
  if ( ZwOpenKey() >= 0 )
  {
    if ( ZwQueryValueKey() >= 0 && v1 == 4 && v2 == 4 )
    {
LABEL_5:
      ZwClose();
      return v3 == 1;
    }
    ZwClose();
  }
  return 0;
}
