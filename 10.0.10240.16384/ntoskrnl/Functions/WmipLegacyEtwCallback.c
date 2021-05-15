// WmipLegacyEtwCallback 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall WmipLegacyEtwCallback(int a1, int a2, int *a3, _DWORD *a4)
{
  _DWORD *v4; // r7
  int v6; // r4 OVERLAPPED
  int v8; // r2
  int v9; // r3
  _DWORD *v10; // r3
  _DWORD *v11; // r9
  int v12; // r2
  int v13; // r0
  _DWORD *v14; // r8
  int v15; // r3
  _DWORD *v16; // r5
  int v17; // r9
  int v18; // r3
  int v19; // r4
  int v20; // r3
  unsigned int v21; // r3

  v4 = a4;
  v6 = 0;
  if ( a2 == 1 || !a2 )
  {
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    if ( v4[20] )
    {
      if ( a2 )
      {
        v8 = a3[1];
        v9 = *a3;
      }
      else
      {
        v9 = 0;
        v8 = 0;
      }
      v4[22] = v9;
      v4[23] = v8;
      v10 = (_DWORD *)v4[8];
      v11 = v4 + 8;
      if ( v10 != v4 + 8 )
      {
        do
        {
          v12 = v10[2];
          if ( (v12 & 0x100000) != 0 && (a2 || (v12 & 0x200000) != 0) )
            ++v6;
          v10 = (_DWORD *)*v10;
        }
        while ( v10 != v11 );
        if ( v6 )
        {
          v13 = ExAllocatePoolWithTag(1, 4 * (v6 + 8), 1885957463);
          v14 = (_DWORD *)v13;
          if ( v13 )
          {
            *(_DWORD *)(v13 + 8) = 2;
            *(_DWORD *)(v13 + 16) = *a3;
            v15 = a3[1];
            *(_BYTE *)(v13 + 28) = a2;
            *(_QWORD *)(v13 + 20) = *(_QWORD *)(&v6 - 1);
            v16 = (_DWORD *)v4[8];
            if ( v16 != v11 )
            {
              v17 = v13;
              do
              {
                v18 = v16[2];
                if ( (v18 & 0x100000) != 0 && (a2 || (v18 & 0x200000) != 0) )
                {
                  v19 = v16[8];
                  WmipReferenceEntry(v19);
                  *(_DWORD *)(v17 + 32) = v19;
                  v20 = v16[2];
                  v17 += 4;
                  if ( a2 )
                    v21 = v20 | 0x200000;
                  else
                    v21 = v20 & 0xFFDFFFFF;
                  v16[2] = v21;
                }
                v16 = (_DWORD *)*v16;
              }
              while ( v16 != v4 + 8 );
              v4 = a4;
            }
            WmipQueueLegacyEtwWork(v14, v4, 0);
          }
        }
      }
    }
    KeReleaseMutex((int)&WmipSMMutex);
  }
}
