// MiMirrorNodeLargePages 
 
unsigned int __fastcall MiMirrorNodeLargePages(unsigned int result, int a2)
{
  unsigned int v2; // r6
  unsigned int v3; // r8
  _DWORD **v4; // r5
  int v5; // r9
  _DWORD *i; // r7
  unsigned int v7; // r1
  unsigned int *v8; // lr
  int v9; // r2
  int v10; // r4
  int v11; // r2
  unsigned int v12; // r3
  int v13; // r2
  unsigned int v14; // r4
  unsigned int v15; // [sp+0h] [bp-40h]
  int v16; // [sp+4h] [bp-3Ch]
  int v17; // [sp+8h] [bp-38h]
  unsigned int v19; // [sp+10h] [bp-30h]
  _DWORD v20[10]; // [sp+18h] [bp-28h] BYREF

  v20[0] = 0;
  v20[1] = 0;
  v20[2] = 0;
  v2 = dword_63F718;
  v3 = result;
  v17 = dword_63F718;
  v19 = dword_63F718 + 104 * (unsigned __int16)KeNumberNodes;
  if ( dword_63F718 < v19 )
  {
    do
    {
      if ( !v3 )
        result = KeAcquireInStackQueuedSpinLock((unsigned int *)(v2 + 100), (unsigned int)v20);
      v4 = (_DWORD **)(v2 + 8);
      v16 = 2;
      do
      {
        v5 = 2;
        do
        {
          for ( i = *v4; i != v4; i = (_DWORD *)*i )
          {
            result = ((int)i - MmPfnDatabase) / 24;
            v15 = result;
            v7 = 1024;
            v8 = (unsigned int *)(*(_DWORD *)(dword_634388 + 4) + 4 * (result >> 5));
            v9 = result & 0x1F;
            if ( (result & 0x1F) == 0 )
              goto LABEL_11;
            v10 = 32 - v9;
            __dmb(0xBu);
            v11 = ~(((1 << (32 - v9)) - 1) << v9);
            do
              result = __ldrex(v8);
            while ( __strex(result & v11, v8) );
            __dmb(0xBu);
            v7 = 1024 - v10;
            ++v8;
            if ( (unsigned int)(1024 - v10) >= 0x20 )
            {
LABEL_11:
              v12 = v7 >> 5;
              do
              {
                v7 -= 32;
                *v8++ = 0;
                --v12;
              }
              while ( v12 );
            }
            if ( v7 )
            {
              __dmb(0xBu);
              v13 = ~((1 << v7) - 1);
              do
              {
                v14 = __ldrex(v8);
                result = v14 & v13;
              }
              while ( __strex(v14 & v13, v8) );
              __dmb(0xBu);
            }
            if ( v3 )
            {
              if ( *(_DWORD *)(a2 + 12) )
                result = (unsigned int)RtlClearBits((_BYTE *)dword_634384, v15, 0x400u);
            }
            else
            {
              result = (unsigned int)RtlSetBits((_BYTE *)dword_634384, v15, 0x400u);
            }
          }
          v4 += 2;
          --v5;
        }
        while ( v5 );
        --v16;
      }
      while ( v16 );
      if ( !v3 )
        result = KeReleaseInStackQueuedSpinLock((int)v20);
      v2 = v17 + 104;
      v17 = v2;
    }
    while ( v2 < v19 );
  }
  return result;
}
