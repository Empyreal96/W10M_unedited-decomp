// ExGetSessionPoolTagInformation 
 
int __fastcall ExGetSessionPoolTagInformation(int a1, int a2, _DWORD *a3, int *a4)
{
  int v5; // r4
  int v8; // r0
  int v9; // r5
  int v10; // r0
  int v11; // r3
  int v12; // r4
  int v13; // r2
  int v14; // r3
  int v15; // [sp+8h] [bp-48h] BYREF
  int v16; // [sp+Ch] [bp-44h] BYREF
  int *v17; // [sp+10h] [bp-40h]
  int v18; // [sp+14h] [bp-3Ch] BYREF
  _BYTE v19[56]; // [sp+18h] [bp-38h] BYREF

  v17 = a4;
  v5 = 0;
  *a3 = 0;
  if ( a2 )
  {
    v5 = ExLockUserBuffer(a1, a2, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A), 1, &v16, &v15);
    if ( v5 >= 0 )
      return sub_7D5CCC();
  }
  else
  {
    MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
    if ( *v17 != -1 )
      JUMPOUT(0x7D5CDC);
    v15 = 0;
    while ( 1 )
    {
      v8 = MmGetNextSession();
      v9 = v8;
      if ( !v8 )
        break;
      v10 = MmGetSessionIdEx(v8);
      v16 = v10;
      v11 = *v17;
      if ( *v17 == -1 || v11 == v10 )
      {
        v5 = MmAttachSession(v9, (int)v19, v10, v11);
        if ( v5 >= 0 )
        {
          v12 = ExGetAttachedSessionPoolTagInfo(0, a2, &v18, v16);
          MmDetachSession(v9, (int)v19, v13, v14);
          if ( v12 >= 0 )
            JUMPOUT(0x7D5D08);
          JUMPOUT(0x7D5CFC);
        }
        break;
      }
    }
    *a3 = v15;
  }
  return v5;
}
