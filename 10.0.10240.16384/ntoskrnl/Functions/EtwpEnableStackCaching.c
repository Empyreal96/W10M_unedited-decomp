// EtwpEnableStackCaching 
 
int __fastcall EtwpEnableStackCaching(_DWORD *a1, unsigned int a2, unsigned int a3)
{
  int v3; // r6
  unsigned int v4; // r4
  unsigned int v5; // r7
  _DWORD *v7; // r0
  unsigned __int64 *v8; // r5
  _DWORD *v9; // r3
  unsigned int v10; // r7
  int v11; // r4
  _DWORD *v12; // r0

  v3 = 0;
  v4 = a3;
  v5 = a2;
  if ( a1[156] )
    return -1073741053;
  if ( a2 < 0x300000 )
    v5 = 3145728;
  if ( v5 > 0x3200000 )
    v5 = 52428800;
  if ( a3 < 0x100 )
    v4 = 256;
  if ( v4 > 0x1000 )
    v4 = 4096;
  v7 = (_DWORD *)ExAllocatePoolWithTag(512, 12 * v4 + 16, 1937208389);
  v8 = (unsigned __int64 *)v7;
  if ( v7 )
  {
    *v7 = 0;
    v7[1] = 0;
    v7[2] = 0;
    v7[3] = 0;
    v7[1] = v4;
    *v7 = *a1;
    v7[2] = 0;
    v7[3] = 0;
    if ( v4 )
    {
      v9 = v7 + 4;
      do
      {
        v9[1] = v9;
        v9[2] = 0;
        *v9 = v9;
        v9 += 3;
        --v4;
      }
      while ( v4 );
    }
    v10 = v5 / 0x98;
    v11 = 0;
    if ( !v10 )
    {
LABEL_19:
      a1[156] = v8;
      __dmb(0xFu);
      a1[152] |= 0x1000000u;
      return v3;
    }
    while ( 1 )
    {
      v12 = (_DWORD *)ExAllocatePoolWithTag(512, 152, 2021094469);
      if ( !v12 )
        break;
      v12[3] = 0;
      RtlpInterlockedPushEntrySList(v8 + 1, v12);
      if ( ++v11 >= v10 )
        goto LABEL_19;
    }
    EtwpFreeStackCache(v8);
  }
  return -1073741801;
}
