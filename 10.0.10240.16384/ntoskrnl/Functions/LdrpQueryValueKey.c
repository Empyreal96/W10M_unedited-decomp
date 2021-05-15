// LdrpQueryValueKey 
 
int __fastcall LdrpQueryValueKey(int a1, int a2, _DWORD *a3, int a4, unsigned int *a5)
{
  unsigned int v7; // r7
  unsigned int v8; // r7
  _BYTE *v9; // r0
  unsigned int v10; // r5
  int v11; // r0
  int v12; // r4
  unsigned int v14; // r2

  if ( a4 )
  {
    if ( !a5 )
      return -1073741811;
    goto LABEL_3;
  }
  if ( a5 )
  {
LABEL_3:
    v7 = *a5;
    goto LABEL_4;
  }
  v7 = 0;
LABEL_4:
  v8 = v7 + 12;
  if ( v8 )
  {
    v9 = (_BYTE *)ExAllocatePoolWithTag(1, v8, 1920232557);
    v10 = (unsigned int)v9;
    if ( !v9 )
      return -1073741670;
    memset(v9, 0, v8);
  }
  else
  {
    v10 = 0;
  }
  if ( !v10 )
    return -1073741670;
  v11 = ZwQueryValueKey();
  v12 = v11;
  if ( v11 == -1073741772 )
    goto LABEL_9;
  if ( v11 < 0 )
  {
LABEL_10:
    if ( v12 != -2147483643 )
    {
LABEL_11:
      ExFreePoolWithTag(v10);
      return v12;
    }
LABEL_22:
    if ( a5 )
      *a5 = *(_DWORD *)(v10 + 8);
    if ( a3 )
      *a3 = *(_DWORD *)(v10 + 4);
    goto LABEL_11;
  }
  if ( !a4 || !a5 )
  {
LABEL_9:
    if ( v12 >= 0 )
      goto LABEL_22;
    goto LABEL_10;
  }
  v14 = *(_DWORD *)(v10 + 8);
  if ( v14 <= *a5 )
  {
    if ( v14 <= v8 )
      memmove(a4, v10 + 12, v14);
    goto LABEL_9;
  }
  return sub_80C0D8();
}
