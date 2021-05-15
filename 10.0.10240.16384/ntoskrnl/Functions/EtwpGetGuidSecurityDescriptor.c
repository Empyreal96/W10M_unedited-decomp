// EtwpGetGuidSecurityDescriptor 
 
int __fastcall EtwpGetGuidSecurityDescriptor(int a1, int *a2)
{
  int v3; // r4
  int v4; // r0
  int v5; // r5
  int v7; // r0

  v3 = 0;
  *a2 = 0;
  while ( 1 )
  {
    if ( v3 )
      ExFreePoolWithTag(v3);
    v3 = ExAllocatePoolWithTag(1, 524, 1350005829);
    if ( !v3 )
      break;
    v4 = ZwQueryValueKey();
    v5 = v4;
    if ( v4 != -2147483643 && v4 != -1073741789 )
      goto LABEL_7;
  }
  v5 = -1073741670;
LABEL_7:
  if ( v5 >= 0 && *(_DWORD *)(v3 + 4) == 3 )
  {
    if ( SeValidSecurityDescriptor(*(_DWORD *)(v3 + 8), v3 + 12) )
    {
      v7 = ExAllocatePoolWithTag(1, *(_DWORD *)(v3 + 8), 1350005829);
      *a2 = v7;
      if ( v7 )
        memmove(v7, v3 + 12, *(_DWORD *)(v3 + 8));
      else
        v5 = -1073741670;
    }
    else
    {
      v5 = -1073741703;
    }
  }
  if ( v3 )
    ExFreePoolWithTag(v3);
  return v5;
}
