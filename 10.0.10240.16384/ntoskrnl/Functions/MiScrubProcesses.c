// MiScrubProcesses 
 
int __fastcall MiScrubProcesses(int a1, _DWORD *a2)
{
  _DWORD *v2; // r5
  int v3; // r4
  int result; // r0
  int v5; // r7
  int *v6; // r6
  int v7; // r10
  int v8; // r2
  int v9; // r9
  _DWORD *v10; // r3
  _DWORD *v11; // r5
  _DWORD *v12; // r3
  int v13; // r8
  _DWORD *v14; // r2
  int v15; // r4
  int v16; // r2
  unsigned int *v17; // r9
  unsigned int v18; // r4
  unsigned int v19; // r0
  int v20; // r5
  int v21; // r8
  int *v22; // r0
  int v23; // r0
  int v24; // r4
  unsigned int *v25; // r2
  int v26; // r0
  __int16 v27; // r3
  int v30; // [sp+Ch] [bp-64h]
  _DWORD v31[10]; // [sp+10h] [bp-60h] BYREF
  char v32[56]; // [sp+38h] [bp-38h] BYREF

  v2 = a2;
  v3 = a1;
  result = MiInitializeScrubPacket(-1, a1, v31);
  if ( result >= 0 )
  {
    v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v30 = v5;
    v6 = PsGetNextProcess(0);
    if ( v6 )
    {
      do
      {
        if ( *(_DWORD *)(v3 + 4) )
          break;
        v7 = v6[82];
        if ( v7 || v6[179] )
        {
          KiStackAttachProcess((int)v6, 0, (int)v32);
          LOCK_ADDRESS_SPACE(v5, (int)v6);
          if ( (v6[48] & 0x20) == 0 )
          {
            v9 = v6[179];
            v10 = (_DWORD *)v6[159];
            v11 = 0;
            while ( v10 )
            {
              v11 = v10;
              v10 = (_DWORD *)*v10;
            }
            while ( v9 && v11 )
            {
              v12 = (_DWORD *)v11[1];
              v13 = (int)v11;
              v14 = v11;
              if ( v12 )
              {
                do
                {
                  v11 = v12;
                  v12 = (_DWORD *)*v12;
                }
                while ( v12 );
              }
              else
              {
                while ( 1 )
                {
                  v11 = (_DWORD *)(v11[2] & 0xFFFFFFFC);
                  if ( !v11 || (_DWORD *)*v11 == v14 )
                    break;
                  v14 = v11;
                }
              }
              if ( (*(_DWORD *)(v13 + 28) & 7) == 5 || MiVadMapsLargeImage(v13) )
              {
                MiLockVad(v5, v13);
                if ( MiVadDeleted(v13) )
                {
                  MiUnlockVad(v5, v13);
                }
                else
                {
                  --v9;
                  v15 = MiScrubLargeMappedPage(v13, (int)v31, (int)v6, v3);
                  MiUnlockVad(v5, v13);
                  if ( !v15 )
                    goto LABEL_41;
                  v3 = a1;
                }
              }
            }
            if ( v7 )
            {
              --*(_WORD *)(v5 + 310);
              ExAcquireAutoExpandPushLockExclusive(v7 + 4, 0, v8);
              v17 = *(unsigned int **)v7;
              if ( *(_DWORD *)v7 )
              {
                v18 = 0;
                do
                {
                  if ( *(_DWORD *)(a1 + 4) )
                    break;
                  v19 = RtlFindSetBits(v17, 1u, v18);
                  v20 = v19;
                  if ( v19 < v18 || v19 == -1 )
                    break;
                  v21 = MmPfnDatabase + 24 * v19;
                  v22 = *(int **)(v21 + 4);
                  if ( v22 )
                    v23 = MiScrubAweMappedPage(v22, v20, (int)v31, (int)v6);
                  else
                    v23 = MiScrubPage((int)v31, v31[4], v21);
                  if ( v23 < 0 )
                  {
                    v24 = MiLockPage(v21);
                    MiMakePageBad(v21, 0, v25);
                    MiUnlockPage(v21, v24);
                  }
                  v18 = v20 + 1;
                }
                while ( v20 + 1 < *v17 );
                v5 = v30;
              }
              v26 = ExReleaseAutoExpandPushLockExclusive((int *)(v7 + 4), 0, v16);
              v27 = *(_WORD *)(v5 + 310) + 1;
              *(_WORD *)(v5 + 310) = v27;
              if ( !v27 && *(_DWORD *)(v5 + 100) != v5 + 100 )
                KiCheckForKernelApcDelivery(v26);
            }
          }
LABEL_41:
          UNLOCK_ADDRESS_SPACE(v5, (int)v6);
          KiUnstackDetachProcess((unsigned int)v32, 0);
          v3 = a1;
        }
        v6 = PsGetNextProcess((int)v6);
      }
      while ( v6 );
      v2 = a2;
    }
    *v2 = v31[6];
    MiReleaseScrubPacket((int)v31);
    result = 0;
  }
  return result;
}
