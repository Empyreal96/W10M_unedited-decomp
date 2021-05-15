// PfpProcessScenarioPhase 
 
int __fastcall PfpProcessScenarioPhase(_DWORD *a1, char a2)
{
  int v3; // r5
  char v4; // r1
  int v6; // r3
  unsigned int v7; // r2
  int v8; // r3
  int v9; // r0
  int v10; // r3
  int v11; // r3
  int v12; // r2
  int v13; // r3
  int v14; // r1
  int v15; // r0
  int v16; // r3
  unsigned int v17; // r5
  int v18; // r0

  v3 = a2;
  v4 = 0;
  if ( *a1 != 4 )
    return -1073741811;
  v6 = a1[1];
  if ( v6 < 6 && v6 > 0 )
  {
    v7 = a1[4];
    if ( (v7 & 1) != 0 )
      v4 = 1;
    if ( v6 <= 2 )
      goto LABEL_10;
    if ( v6 == 3 )
    {
      v13 = a1[2];
      if ( v13 )
      {
        if ( v13 != 1 || dword_6372AC != 3 )
          return 0;
        PfpScenCtxPrefetchWait((unsigned int)&unk_637290, 3, 0x1388u);
        PfpLogScenarioEvent(3, 0, 0, dword_6372B0, 0);
        v11 = 0;
        v12 = 0;
        v14 = 3;
LABEL_32:
        PfpScenCtxScenarioSet((unsigned int)&unk_637290, v14, v12, v11);
        return 0;
      }
      v15 = PsGetCurrentProcessSessionId();
      v16 = MEMORY[0xFFFF92D8];
      __dmb(0xBu);
      if ( v15 != v16 )
        return 0;
      if ( dword_643A6C >= (unsigned int)dword_643A70 )
        return 0;
      v17 = 0;
      v18 = MmGetNextSession();
      if ( !v18 )
        return 0;
      while ( ++v17 < 3 )
      {
        v18 = MmGetNextSession();
        if ( !v18 )
          goto LABEL_29;
      }
      MmQuitNextSession(v18);
LABEL_29:
      if ( v17 < 3 )
        return 0;
      v11 = a1[5];
      v12 = 3;
    }
    else
    {
      if ( v6 != 4 )
      {
LABEL_10:
        if ( v3 )
          return -1073741790;
        if ( v6 == 5 )
          v4 |= 4u;
        PfPowerActionNotify(a1[2], v4, v7 >> 1);
        return 0;
      }
      v8 = a1[2];
      if ( v8 )
      {
        if ( v8 == 1 )
        {
          v9 = PsGetCurrentProcessSessionId();
          v10 = MEMORY[0xFFFF92D8];
          __dmb(0xBu);
          if ( v9 == v10 )
          {
            PfpScenCtxScenarioSet((unsigned int)&unk_637290, 4, 0, 0);
            if ( dword_643A6C < (unsigned int)dword_643A70 )
              PfpLogScenarioEvent(5, 2, 3, dword_6372B0, 1);
          }
        }
        return 0;
      }
      v11 = 0;
      v12 = 4;
    }
    v14 = 0;
    goto LABEL_32;
  }
  return -1073741701;
}
