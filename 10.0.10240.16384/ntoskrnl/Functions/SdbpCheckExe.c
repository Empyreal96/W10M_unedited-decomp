// SdbpCheckExe 
 
int __fastcall SdbpCheckExe(int a1, int a2, int a3, int *a4, int a5, int a6, int *a7, _BYTE *a8)
{
  int v12; // r6
  int v13; // r0
  int v14; // r2
  int v15; // r3
  int v16; // r0
  int v17; // r0
  int v18; // r0
  int v19; // r0
  int v20; // r4
  int v21; // r1
  int v22; // r3
  int *v23; // r2
  int v25; // [sp+8h] [bp-20h] BYREF
  int v26[7]; // [sp+Ch] [bp-1Ch] BYREF

  v25 = 2;
  v26[0] = 0;
  v12 = 0;
  v13 = SdbFindFirstTag(a2, a3, 24582);
  if ( v13 )
    SdbGetStringTagPtr(a2, v13, v14, v15);
  v16 = SdbFindFirstTag(a2, a3, 16418);
  if ( !v16 || (v17 = SdbReadDWORDTag(a2, v16, -1), v17 == -1) || (v17 & *(_DWORD *)(a1 + 408)) != 0 )
  {
    v18 = SdbFindFirstTag(a2, a3, 16415);
    if ( !v18 || (v19 = SdbReadDWORDTag(a2, v18, -1), v19 == -1) || (v19 & *(_DWORD *)(a1 + 412)) != 0 )
    {
      if ( SdbpCheckForMatch(a1, a2, a3, a5, &v25, v26) )
      {
        v20 = v25;
        if ( (a6 != 1 || v25 == 2) && (a6 != 2 || v25 != 2) )
        {
          if ( v25 == 1 )
          {
            memset(a8, 0, 128);
            *a4 = 0;
          }
          v21 = *a4;
          if ( (unsigned int)*a4 < 0x10 )
          {
            v22 = v26[0];
            v23 = (int *)&a8[8 * v21];
            *v23 = a3;
            v23[1] = v22;
            *a4 = v21 + 1;
            v12 = 1;
            if ( a7 )
              *a7 = v20;
          }
          else
          {
            AslLogCallPrintf(1, (int)"SdbpCheckExe", 2689, "The number of matching EXEs exceeded the max allowed");
            ++*a4;
            v12 = 0;
          }
        }
      }
    }
  }
  return v12;
}
