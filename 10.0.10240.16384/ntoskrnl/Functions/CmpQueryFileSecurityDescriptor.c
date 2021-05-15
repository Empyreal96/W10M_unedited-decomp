// CmpQueryFileSecurityDescriptor 
 
int __fastcall CmpQueryFileSecurityDescriptor(int a1, int *a2)
{
  int v3; // r5
  int v4; // r0
  int v5; // r4

  v3 = 0;
  v4 = ZwQuerySecurityObject();
  v5 = v4;
  if ( v4 != -1073741789 )
  {
    if ( !v4 )
      v5 = -1073741823;
    goto LABEL_4;
  }
  v3 = ExAllocatePoolWithTag(1, 0, 1685278019);
  if ( !v3 )
  {
    v5 = -1073741670;
    goto LABEL_4;
  }
  v5 = ZwQuerySecurityObject();
  if ( v5 >= 0 )
  {
LABEL_4:
    *a2 = v3;
    return v5;
  }
  return sub_7C2E7C();
}
