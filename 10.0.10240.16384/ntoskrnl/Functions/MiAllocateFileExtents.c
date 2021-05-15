// MiAllocateFileExtents 
 
int __fastcall MiAllocateFileExtents(int *a1, _DWORD *a2)
{
  int v2; // r4
  int v3; // r6
  int v5; // r0
  int v6; // r2
  int v7; // r5
  unsigned int v8; // r1
  int v9; // r4
  _DWORD *v10; // r5
  unsigned int *v11; // r0
  int *v12; // r2
  unsigned int v13; // r6
  int *v14; // lr
  unsigned int *v15; // r1
  unsigned int v16; // r7
  unsigned int i; // r4
  int v18; // r3
  unsigned int v19; // r1
  unsigned int v20; // r3
  int v22; // [sp+0h] [bp-28h]
  int v23; // [sp+4h] [bp-24h]
  unsigned int v24[6]; // [sp+10h] [bp-18h] BYREF

  v3 = a1[9] + a1[7];
  v2 = *a1;
  v24[0] = 0;
  *a2 = 0;
  v5 = MI_REFERENCE_CONTROL_AREA_FILE(v2);
  v7 = FsRtlGetFileExtents(v5, v5, v6, (int)v24, v22, v23, v24);
  MI_DEREFERENCE_CONTROL_AREA_FILE(v2, v8);
  if ( v7 >= 0 )
  {
    v9 = v3;
    v10 = (_DWORD *)ExAllocatePoolWithTag(512, 4 * v3 + 4, 1699113293);
    v11 = (unsigned int *)v24[0];
    if ( v10 )
    {
      *v10 = 0;
      v12 = v10 + 1;
      v13 = 0;
      v14 = &v10[v9 + 1];
      if ( *v11 )
      {
        v15 = v11;
        do
        {
          v16 = v15[3];
          for ( i = 0; i < v16; ++v12 )
          {
            v18 = v15[2] + i++;
            *v12 = v18;
          }
          ++v13;
          v15 += 2;
        }
        while ( v13 < *v11 );
      }
      v19 = 0;
      if ( v12 > v14 )
        v20 = 0;
      else
        v20 = (unsigned int)((char *)v14 - (char *)v12 + 3) >> 2;
      if ( v20 )
      {
        do
        {
          ++v19;
          *v12++ = -1;
        }
        while ( v19 < v20 );
      }
      ExFreePoolWithTag((unsigned int)v11);
      *a2 = v10;
      v7 = 0;
    }
    else
    {
      ExFreePoolWithTag(v24[0]);
      v7 = -1073741670;
    }
  }
  return v7;
}
