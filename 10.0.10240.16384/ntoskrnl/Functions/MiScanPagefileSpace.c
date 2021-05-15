// MiScanPagefileSpace 
 
int __fastcall MiScanPagefileSpace(unsigned __int16 *a1)
{
  int v2; // r5
  int v3; // r9
  _DWORD *v4; // r8
  _DWORD *v5; // r2
  __int64 v6; // t1
  unsigned int v7; // r4
  unsigned int v8; // r1
  int v9; // r3
  int v10; // r3
  unsigned int v11; // r5
  int v12; // r6
  int v13; // r3
  int v14; // r3
  int v15; // r3
  int result; // r0
  unsigned int v17; // [sp+0h] [bp-30h]
  int v18; // [sp+4h] [bp-2Ch]
  _DWORD *v19; // [sp+8h] [bp-28h]
  _DWORD *v20; // [sp+Ch] [bp-24h]

  v2 = *a1;
  v3 = 0;
  v18 = v2;
  v4 = (_DWORD *)MiReferencePageRuns((int)a1, 0);
  v19 = v4;
  v5 = v4;
  do
  {
    v6 = *((_QWORD *)v5 + 1);
    v20 = v5 + 2;
    v7 = MmPfnDatabase + 24 * v6;
    v8 = v7 + 24 * HIDWORD(v6);
    v17 = v8;
    if ( v7 < v8 )
    {
      do
      {
        if ( !v2 )
        {
          v9 = *(_BYTE *)(v7 + 18) & 7;
          if ( v9 == 2 || v9 == 3 || v9 == 7 )
          {
            v10 = *(_DWORD *)(v7 + 8);
            if ( (v10 & 0x400) == 0
              && (v10 & 0x10) != 0
              && (*(_DWORD *)(v7 + 20) & 0xFFFFF) != 1048573
              && *(_WORD *)(v7 + 16)
              && (*(_BYTE *)(v7 + 18) & 0x20) == 0
              && (*(_BYTE *)(v7 + 18) & 8) == 0
              && (*(_BYTE *)(v7 + 19) & 0x10) == 0 )
            {
              v11 = 0;
              v12 = MiLockPage(v7);
              v13 = *(_BYTE *)(v7 + 18) & 7;
              if ( v13 == 2 || v13 == 3 || v13 == 7 )
              {
                v14 = *(_DWORD *)(v7 + 8);
                if ( (v14 & 0x400) == 0
                  && (v14 & 0x10) != 0
                  && (*(_DWORD *)(v7 + 20) & 0xFFFFF) != 1048573
                  && *(_WORD *)(v7 + 16)
                  && (*(_BYTE *)(v7 + 18) & 0x20) == 0
                  && (*(_BYTE *)(v7 + 18) & 8) == 0
                  && (*(_BYTE *)(v7 + 19) & 0x10) == 0 )
                {
                  v11 = MiCaptureDirtyBitToPfn(v7);
                }
              }
              MiUnlockPage(v7, v12);
              if ( v11 )
                MiReleasePageFileInfo((int)a1, v11, 0, v15);
              v8 = v17;
              v2 = v18;
            }
          }
        }
        v7 += 24;
      }
      while ( v7 < v8 );
      v4 = v19;
    }
    ++v3;
    v5 = v20;
  }
  while ( v3 != *v4 );
  result = MiDereferencePageRuns((int)v4);
  *((_DWORD *)a1 + 145) = 0;
  return result;
}
