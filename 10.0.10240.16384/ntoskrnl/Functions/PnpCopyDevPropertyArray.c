// PnpCopyDevPropertyArray 
 
int __fastcall PnpCopyDevPropertyArray(unsigned int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // r5
  _BYTE *v10; // r0
  unsigned int v11; // r9
  int v12; // r8
  int v13[8]; // [sp+0h] [bp-20h] BYREF

  v13[0] = (int)a4;
  v6 = 0;
  *a4 = 0;
  *a5 = 0;
  if ( !a2 )
    return v6;
  if ( !a1 )
    return v6;
  v6 = RtlULongLongToULong(40 * a1, (40 * (unsigned __int64)a1) >> 32, v13);
  if ( v6 < 0 )
    return v6;
  v10 = (_BYTE *)ExAllocatePoolWithTag(1, v13[0], 1466986064);
  *a5 = v10;
  if ( v10 )
  {
    memset(v10, 0, v13[0]);
    v11 = 0;
    if ( a1 )
    {
      v12 = 0;
      do
      {
        v6 = PnpCopyDevProperty(v12 + a2, 1466986064, v12 + *a5);
        if ( v6 < 0 )
          JUMPOUT(0x7E0B6C);
        ++v11;
        v12 += 40;
        ++*a4;
      }
      while ( v11 < a1 );
    }
    return v6;
  }
  return sub_7E0B68();
}
