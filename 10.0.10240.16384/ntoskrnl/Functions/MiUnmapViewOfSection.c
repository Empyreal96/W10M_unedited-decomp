// MiUnmapViewOfSection 
 
int __fastcall MiUnmapViewOfSection(int a1, unsigned int a2, int a3)
{
  int v5; // r9
  int v6; // r7
  _DWORD *v7; // r0
  int v8; // r4
  int v9; // r2
  int v11; // r1
  int v12; // r3
  int v13; // r5
  int v14; // r8
  int v15; // r0
  unsigned int v16; // r10
  unsigned int v17; // r2
  int v18; // r3
  unsigned int v19; // r3
  int *v20; // r5
  int v21; // [sp+18h] [bp-40h] BYREF
  int v22; // [sp+1Ch] [bp-3Ch]
  char v23[56]; // [sp+20h] [bp-38h] BYREF

  v22 = a3;
  v5 = 0;
  v6 = 0;
  if ( *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) != a1 )
  {
    KiStackAttachProcess(a1, 0, (int)v23);
    v5 = 1;
  }
  v7 = (_DWORD *)MiObtainReferencedVad(a2, &v21);
  v8 = (int)v7;
  if ( v7 )
  {
    v9 = v7[7];
    if ( (v9 & 0x8000) != 0 )
      return sub_8030A4();
    v11 = v7[3];
    if ( (v7[7] & 7) == 2 )
      v6 = v11 << 12;
    v12 = v7[4] - v11;
    v21 = (v12 + 1) << 12;
    if ( (v9 & 0x4000) == 0 || (v13 = MiCheckSecuredVad(v7, v11 << 12, (v12 + 1) << 12, 0x55u), v13 >= 0) )
    {
      if ( (PerfGlobalGroupMask & 4) != 0 )
      {
        if ( v6 )
        {
          if ( *(_DWORD *)(a1 + 176) )
          {
            if ( a1 != PsInitialSystemProcess && (*(_DWORD *)(v8 + 28) & 0xF8) == 56 )
            {
              v20 = **(int ***)(v8 + 44);
              if ( v20 )
              {
                if ( v20[8] )
                {
                  v14 = *v20;
                  v15 = MI_REFERENCE_CONTROL_AREA_FILE((int)v20);
                  v16 = v15;
                  if ( (*(_DWORD *)(v8 + 40) & 0x10000000) != 0 )
                  {
                    v17 = 0;
                    v18 = 0;
                  }
                  else
                  {
                    v19 = *(unsigned __int8 *)(v14 + 11);
                    v17 = v19 >> 4;
                    v18 = (v19 >> 1) & 7;
                  }
                  PerfLogImageUnload(
                    v15 + 48,
                    v15,
                    *(_DWORD *)(a1 + 176),
                    v6,
                    v21,
                    *(_DWORD *)(*(_DWORD *)(v14 + 36) + 44),
                    v17,
                    v18,
                    1);
                  MI_DEREFERENCE_CONTROL_AREA_FILE((int)v20, v16);
                }
              }
            }
          }
        }
      }
      MiUnmapVad(v8, v22);
      v8 = 0;
      v13 = 0;
    }
    if ( v8 )
      MiUnlockAndDereferenceVad(v8);
  }
  else
  {
    v13 = v21;
    if ( v21 == -1073741664 )
      v13 = -1073741799;
  }
  if ( v5 == 1 )
    KiUnstackDetachProcess((unsigned int)v23, 0);
  if ( v6 )
    DbgkUnMapViewOfSection(a1);
  return v13;
}
