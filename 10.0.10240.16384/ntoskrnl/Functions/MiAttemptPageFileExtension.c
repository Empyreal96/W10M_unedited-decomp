// MiAttemptPageFileExtension 
 
unsigned int __fastcall MiAttemptPageFileExtension(int a1, unsigned int a2)
{
  int v3; // r10
  unsigned int v5; // r4
  unsigned int i; // r6
  unsigned int v7; // r7
  __int64 v8; // kr00_8
  unsigned int v9; // r1
  _DWORD *v10; // r0
  int v11; // r3
  __int64 v13; // [sp+8h] [bp-48h] BYREF
  char v14[8]; // [sp+10h] [bp-40h] BYREF
  char v15[8]; // [sp+18h] [bp-38h] BYREF
  __int64 v16; // [sp+20h] [bp-30h]
  int v17; // [sp+28h] [bp-28h]
  int v18; // [sp+2Ch] [bp-24h]

  v3 = *(_DWORD *)(a1 + 128);
  if ( *(_DWORD *)a1 != *(_DWORD *)(a1 + 4)
    && IoQueryVolumeInformation(*(_DWORD *)(a1 + 32), 3, 24, (int)v15, (int)v14) >= 0 )
  {
    for ( i = 0x4000; ; i = 4096 )
    {
      if ( a2 >= i )
      {
        v7 = a2;
        i = 4096;
      }
      else
      {
        v7 = i;
      }
      v8 = *(_QWORD *)a1;
      if ( v7 > HIDWORD(v8) - (int)v8 )
        v7 = HIDWORD(v8) - v8;
      v9 = v18 * v17 * v16;
      if ( is_mul_ok(v16, v18 * v17) && v9 <= 0x10000000 )
        break;
      v5 = ((__CFADD__(v9, -268435456) + ((v16 * (unsigned __int64)(unsigned int)(v18 * v17)) >> 32) - 1) << 20) | ((v9 - 0x10000000) >> 12);
      if ( v5 > v7 )
        v5 = v7;
      if ( (*(_WORD *)(a1 + 96) & 0x10) != 0 && v5 < a2 )
        break;
      LODWORD(v13) = ((_DWORD)v8 + v5) << 12;
      v10 = *(_DWORD **)(a1 + 32);
      HIDWORD(v13) = (__int64)((unsigned int)v8 + (unsigned __int64)v5) >> 20;
      if ( !IoSetInformation(v10, 20, 8, (int)&v13) )
      {
        MiFinishPageFileExtension(v3, a1, v5, v11);
        return v5;
      }
      if ( i == 4096 )
        return 0;
    }
  }
  return 0;
}
