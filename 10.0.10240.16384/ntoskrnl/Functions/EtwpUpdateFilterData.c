// EtwpUpdateFilterData 
 
int __fastcall EtwpUpdateFilterData(int a1, int a2, int a3, int a4)
{
  int v6; // r7
  int v8; // r3
  _BYTE *v10; // r0
  _BYTE *v11; // r4
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r2
  bool v15; // cf
  unsigned int *v16; // r2
  unsigned int v17; // r1
  unsigned int v19; // [sp+10h] [bp-48h]
  int v20; // [sp+18h] [bp-40h]
  int v21; // [sp+1Ch] [bp-3Ch]
  __int64 v22; // [sp+30h] [bp-28h]

  v6 = a3;
  if ( !a3 || !*(_DWORD *)(a3 + 116) )
    a4 = 1;
  v8 = *(_DWORD *)(a1 + 344);
  if ( a4 )
  {
    if ( v8 )
      return sub_807C60();
  }
  else
  {
    if ( !v8 )
    {
      v10 = (_BYTE *)ExAllocatePoolWithTag(512, 288, 1182233669);
      v11 = v10;
      if ( !v10 )
        JUMPOUT(0x807D88);
      memset(v10, 0, 288);
      *(_DWORD *)(a1 + 344) = v11;
    }
    __dmb(0xBu);
    v12 = (unsigned int *)(*(_DWORD *)(a1 + 344) + 36 * a2);
    do
      v13 = __ldrex(v12);
    while ( __strex(0, v12) );
    v19 = v13;
    __dmb(0xBu);
    v20 = 0;
    if ( *(_DWORD *)(v6 + 116) )
    {
      v14 = a3 + 120;
      v21 = a3 + 120;
      do
      {
        v22 = *(_QWORD *)(v14 + 8);
        if ( HIDWORD(v22) > 0x80000020 )
          JUMPOUT(0x807E30);
        switch ( HIDWORD(v22) )
        {
          case 0x80000020:
            JUMPOUT(0x807E12);
          case 0x80000000:
            JUMPOUT(0x807DFA);
          case 0x80000004:
            JUMPOUT(0x807DE4);
          case 0x80000008:
            JUMPOUT(0x807DCA);
          case 0x80000010:
            JUMPOUT(0x807D8E);
        }
        v14 = v21 + 16;
        v15 = (unsigned int)++v20 >= *(_DWORD *)(a3 + 116);
        v21 += 16;
      }
      while ( !v15 );
    }
    EtwpUpdateSchematizedFilterData(*(_DWORD *)(a1 + 344) + 36 * a2, 0, 0, 1);
    if ( (v19 & 0x80000004) == -2147483644 )
      JUMPOUT(0x807E8E);
    if ( (v19 & 0x80000008) == -2147483640 )
      JUMPOUT(0x807EAC);
    if ( (v19 & 0x80000010) == -2147483632 )
      JUMPOUT(0x807ECE);
    if ( (v19 & 0x80000020) == -2147483616 )
      JUMPOUT(0x807EF0);
    if ( (v19 & 0x80001000) == -2147479552 )
      JUMPOUT(0x807F12);
    if ( (v19 & 0x80000200) == -2147483136 )
      JUMPOUT(0x807F36);
    if ( (v19 & 0x80000100) == -2147483392 )
      JUMPOUT(0x807F5A);
    __dmb(0xBu);
    v16 = (unsigned int *)(*(_DWORD *)(a1 + 344) + 36 * a2);
    do
      v17 = __ldrex(v16);
    while ( __strex(0, v16) );
    __dmb(0xBu);
  }
  return 0;
}
