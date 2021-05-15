// MiFreeRelocations 
 
int __fastcall MiFreeRelocations(int a1, _DWORD *a2, int a3, int a4)
{
  __int64 v6; // kr00_8
  unsigned int v8; // r0
  _DWORD *v9; // r0
  _DWORD *v10; // r4
  int v11; // [sp+0h] [bp-18h] BYREF
  int v12; // [sp+4h] [bp-14h]
  int v13; // [sp+8h] [bp-10h]
  int v14; // [sp+Ch] [bp-Ch]

  v11 = a1;
  v12 = (int)a2;
  v13 = a3;
  v14 = a4;
  if ( a2 )
  {
    v6 = *(_QWORD *)(a1 + 48);
    v11 = *(_DWORD *)(a1 + 48);
    v12 = WORD2(v6);
    v13 = (HIDWORD(v6) >> 29) & 3;
    if ( (*(_DWORD *)(a1 + 28) & 0x10000000) != 0 )
      return sub_7E9CF4();
    LOBYTE(v14) = 0;
    if ( a2[5] )
    {
      MiReturnImageBase(&v11);
      *(_DWORD *)(a1 + 48) = -1;
    }
    v8 = a2[9];
    if ( v8 )
      ExFreePoolWithTag(v8);
    v9 = (_DWORD *)a2[2];
    if ( v9 )
    {
      do
      {
        v10 = (_DWORD *)*v9;
        ExFreePoolWithTag((unsigned int)v9);
        v9 = v10;
      }
      while ( v10 );
    }
    ExFreePoolWithTag((unsigned int)a2);
  }
  return v11;
}
