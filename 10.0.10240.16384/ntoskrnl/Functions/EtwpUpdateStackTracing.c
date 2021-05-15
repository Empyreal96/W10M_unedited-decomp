// EtwpUpdateStackTracing 
 
int __fastcall EtwpUpdateStackTracing(_DWORD *a1, int a2, unsigned int a3, int a4)
{
  _DWORD *v6; // r5
  int v7; // r6
  _BYTE *v8; // r0
  _BYTE *v9; // r9
  unsigned int *v10; // r2
  unsigned int v11; // r0
  unsigned int i; // r4
  unsigned int v13; // r0
  int varg_r1; // [sp+34h] [bp+Ch]
  unsigned int varg_r2; // [sp+38h] [bp+10h]

  varg_r1 = a2;
  varg_r2 = a3;
  v6 = a1;
  v7 = 0;
  if ( a3 )
  {
    if ( a3 > 0x100 )
      return -1073741811;
    if ( (a1[152] & 0x80) != 0 )
    {
      RtlClearAllBits((int)(a1 + 154));
    }
    else
    {
      v8 = (_BYTE *)ExAllocatePoolWithTag(512, 1024, 1836545093);
      v9 = v8;
      if ( !v8 )
        return -1073741801;
      memset(v8, 0, 1024);
      v6[154] = 0x2000;
      v6[155] = v9;
      __dmb(0xBu);
      v10 = v6 + 152;
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 | 0x2000, v10) );
      __dmb(0xBu);
      if ( (v11 & 0x2000) == 0 )
        EtwpReferenceStackLookasideList();
      v6[152] |= 0x80u;
    }
    for ( i = 0; i < a3; ++i )
    {
      v13 = (*(_DWORD *)(a2 + 4 * i) & 0x1FFFu) >> 3;
      *(_BYTE *)(v13 + v6[155]) |= 1 << (*(_BYTE *)(a2 + 4 * i) & 7);
    }
  }
  else if ( (a1[152] & 0x80) != 0 )
  {
    RtlClearAllBits((int)(a1 + 154));
  }
  return v7;
}
