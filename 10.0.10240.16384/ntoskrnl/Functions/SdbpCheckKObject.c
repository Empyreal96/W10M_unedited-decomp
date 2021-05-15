// SdbpCheckKObject 
 
int __fastcall SdbpCheckKObject(int a1, int a2, unsigned __int16 *a3, int a4, int a5, int a6, _DWORD *a7)
{
  int v10; // r4
  unsigned __int16 *v11; // r6
  int v12; // r8
  int v13; // r5
  int v14; // r0
  unsigned __int16 *v16; // [sp+8h] [bp-58h] BYREF
  int v17; // [sp+Ch] [bp-54h] BYREF
  int v18[20]; // [sp+10h] [bp-50h] BYREF

  v10 = a1;
  v17 = a1;
  v18[0] = 0;
  memset(&v18[1], 0, 44);
  v11 = 0;
  v12 = *(_DWORD *)(v10 + 4);
  v13 = 0;
  v16 = 0;
  if ( a3 )
  {
    v14 = AslFileMappingCreate(&v16, a3, a4, a5, a6);
    v11 = v16;
    if ( v14 < 0 )
      goto LABEL_11;
    v10 = v17;
  }
  memset(v18, 0, 48);
  v18[0] |= 0x1Au;
  v13 = SdbpCreateSearchDBContext(v18, v11);
  if ( v13 )
  {
    v13 = SdbpCheckForMatch(v10, v12, a2, (int)v18, (int *)&v16, (int)&v17);
    if ( v13 )
    {
      if ( a7 )
      {
        v13 = SdbpMatchAcpi(v12, a2, *a7);
        if ( v13 )
        {
          v13 = SdbpMatchOem(v12, a2, a7[1]);
          if ( v13 )
          {
            v13 = SdbpMatchBios(v12, a2, a7[2]);
            if ( v13 )
              v13 = SdbpMatchCpu(v12, a2, a7[3]);
          }
        }
      }
    }
  }
LABEL_11:
  SdbpReleaseSearchDBContext((int)v18);
  AslFileMappingDelete((unsigned int)v11);
  return v13;
}
