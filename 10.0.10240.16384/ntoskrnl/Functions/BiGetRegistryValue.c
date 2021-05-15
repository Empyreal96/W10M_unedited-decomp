// BiGetRegistryValue 
 
int __fastcall BiGetRegistryValue(int a1, unsigned __int16 *a2, int a3, int a4, int *a5, unsigned int *a6)
{
  int v8; // r6
  int v9; // r4
  int v10; // r5
  int v11; // r0
  int v13; // [sp+Ch] [bp-44h]
  unsigned int v14; // [sp+Ch] [bp-44h]
  int v15; // [sp+10h] [bp-40h] BYREF
  int v16; // [sp+14h] [bp-3Ch]
  int v17; // [sp+18h] [bp-38h]
  unsigned __int16 *v18; // [sp+1Ch] [bp-34h]
  _DWORD _28[16]; // [sp+28h] [bp-28h] BYREF

  v16 = a4;
  _28[15] = a4;
  v17 = a3;
  _28[14] = a3;
  v18 = a2;
  _28[13] = a2;
  _28[12] = a1;
  v8 = 0;
  v15 = 0;
  *a5 = 0;
  *a6 = 0;
  RtlInitUnicodeString((unsigned int)_28, a2);
  if ( a3 )
  {
    v9 = BiOpenKey(a1, a3, 131097, &v15);
    v10 = v15;
    if ( v9 < 0 )
      goto LABEL_13;
  }
  else
  {
    v10 = a1;
  }
  v9 = BiZwQueryValueKey();
  if ( v9 == -1073741789 )
  {
    v8 = ExAllocatePoolWithTag(1, v13, 1262764866);
    if ( v8 )
    {
      v9 = BiZwQueryValueKey();
      if ( v9 < 0 )
        goto LABEL_13;
      if ( *(_DWORD *)(v8 + 4) != v16 )
      {
        v9 = -1073741788;
        goto LABEL_13;
      }
      v14 = v13 - 12;
      v11 = ExAllocatePoolWithTag(1, v14, 1262764866);
      *a5 = v11;
      if ( v11 )
      {
        memmove(v11, v8 + 12, v14);
        *a6 = v14;
        v9 = 0;
        goto LABEL_13;
      }
    }
    v9 = -1073741670;
  }
LABEL_13:
  if ( v10 != a1 && v10 )
    BiZwClose();
  if ( v8 )
    ExFreePoolWithTag(v8);
  if ( v9 == -1073741443 )
    __debugbreak();
  return v9;
}
