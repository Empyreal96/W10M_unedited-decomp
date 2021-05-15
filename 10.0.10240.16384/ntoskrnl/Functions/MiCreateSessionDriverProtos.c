// MiCreateSessionDriverProtos 
 
int __fastcall MiCreateSessionDriverProtos(int *a1, int a2, int a3)
{
  int v4; // r3
  unsigned int v7; // r7
  unsigned int v8; // r5
  _DWORD *v9; // r4
  __int16 v10; // r2
  int v11; // r8
  _DWORD *v12; // r2
  int v13; // r3
  _DWORD *v14; // [sp+8h] [bp-58h] BYREF
  int v15; // [sp+Ch] [bp-54h]
  int v16; // [sp+10h] [bp-50h]
  unsigned int v17[18]; // [sp+18h] [bp-48h] BYREF

  v4 = *a1;
  v15 = a3;
  v16 = *(_DWORD *)(v4 + 24);
  if ( MiMapImageInSystemSpace((int)a1, 3, v17) < 0 )
    return 0;
  v7 = v17[0];
  v8 = 0;
  v9 = a1 + 20;
  if ( a1 != (int *)-80 )
  {
    do
    {
      v10 = *((_WORD *)v9 + 8);
      v11 = v9[7];
      if ( (v10 & 8) == 0 && ((MiFlags & 0x80000) != 0 || (MiFlags & 0x30000) == 0 || (v10 & 4) == 0) )
      {
        if ( MiAllocatePerSessionProtos(v9, v7, v8, a2 - v16, &v14) < 0 )
        {
          MiUnmapImageInSystemSpace(v17);
          MiDeleteSessionDriverProtos(a1);
          return 0;
        }
        v12 = v14;
        *v14 = a2 + (v8 << 12);
        v13 = v15;
        v9[3] = v12;
        RtlClearBits(*(_BYTE **)(v13 + 20), v8, v9[7]);
      }
      v9 = (_DWORD *)v9[2];
      v7 += v11 << 12;
      v8 += v11;
    }
    while ( v9 );
  }
  MiUnmapImageInSystemSpace(v17);
  return 1;
}
