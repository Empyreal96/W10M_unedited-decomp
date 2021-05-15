// IopAllocRealFileObject 
 
int __fastcall IopAllocRealFileObject(int a1, int a2, int a3, int a4, char a5, int a6, char a7, int a8)
{
  _QWORD *v8; // r5
  unsigned int v10; // r4
  unsigned int v11; // r6
  int v12; // r7
  int v13; // r4
  int v14; // r6
  int v15; // r5
  int v16; // r2
  int v17; // r3
  int v18; // r3
  int v19; // r0
  int v20; // r2
  int v21; // r7
  __int64 v22; // kr00_8
  int v23; // r0
  char v25[4]; // [sp+10h] [bp-58h] BYREF
  int v26; // [sp+14h] [bp-54h]
  int v27[4]; // [sp+18h] [bp-50h] BYREF
  char v28[8]; // [sp+28h] [bp-40h] BYREF
  int v29[14]; // [sp+30h] [bp-38h] BYREF

  v27[1] = a4;
  v27[2] = a3;
  v29[3] = a4;
  v29[0] = 24;
  v29[2] = 0;
  v26 = a2;
  v8 = IoFileObjectType;
  v29[4] = 0;
  v29[5] = 0;
  v25[0] = 1;
  v29[1] = 0;
  v10 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v11 = v10 + 1408;
  v12 = *(_DWORD *)(v10 + 2848);
  ++*(_DWORD *)(v12 + 12);
  v13 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v12);
  if ( v13 )
    goto LABEL_2;
  ++*(_DWORD *)(v12 + 16);
  v21 = *(_DWORD *)(v11 + 1444);
  ++*(_DWORD *)(v21 + 12);
  v13 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v21);
  if ( v13
    || (v22 = *(_QWORD *)(v21 + 32),
        v23 = *(_DWORD *)(v21 + 28),
        ++*(_DWORD *)(v21 + 16),
        (v13 = (*(int (__fastcall **)(int, _DWORD, _DWORD))(v21 + 40))(v23, HIDWORD(v22), v22)) != 0) )
  {
LABEL_2:
    *(_DWORD *)v13 = *(_DWORD *)(v11 + 20);
    if ( ObpCaptureObjectCreateInformation(0, a5, v29, v28, v13, 0) >= 0 )
    {
      if ( ((_DWORD)v8[6] & *(_DWORD *)v13) == 0 )
      {
        if ( (*(_DWORD *)v13 & 0x10) == 0 )
        {
          *(_QWORD *)(v13 + 12) = v8[10];
          v14 = ObpAllocateObject(v13, a5, v8, v28, 128, v27, v25);
          if ( v14 >= 0 )
          {
            if ( !ObpTraceFlags )
            {
              v15 = v27[0] + 24;
              memset((_BYTE *)(v27[0] + 24), 0, 128);
              if ( a7 )
              {
                *(_DWORD *)(v15 + 12) = *(_DWORD *)(*(_DWORD *)a1 + 12);
                *(_DWORD *)(v15 + 16) = *(_DWORD *)(*(_DWORD *)a1 + 16);
                *(_WORD *)(v15 + 48) = *(_WORD *)(*(_DWORD *)a1 + 48);
                *(_WORD *)(v15 + 50) = *(_WORD *)(*(_DWORD *)a1 + 50);
                *(_DWORD *)(v15 + 52) = *(_DWORD *)(*(_DWORD *)a1 + 52);
                v19 = *(_DWORD *)(*(_DWORD *)a1 + 124);
                if ( v19 )
                  *(_DWORD *)(v15 + 124) = v19;
              }
              else
              {
                if ( (*(_DWORD *)(a6 + 88) & 7) != 0 )
                  v14 = IopAllocateFoExtensionsOnCreate(v15, v26, a6, a8);
                if ( v14 >= 0 )
                {
                  if ( a5 )
                  {
                    if ( (*(_DWORD *)(a6 + 88) & 0x20) != 0 )
                    {
                      if ( (*(_DWORD *)(v26 + 28) & 0x40000) != 0
                        || (v17 = *(_DWORD *)(v26 + 44), v17 == 8)
                        || v17 == 20
                        || v17 == 3
                        || v17 == 32
                        || v17 == 53 )
                      {
                        v14 = IopRetrieveTransactionParameters(v26, a6, a8, v15);
                      }
                    }
                  }
                  if ( a5 )
                  {
                    if ( v14 >= 0 )
                    {
                      v18 = *(_DWORD *)(a6 + 40);
                      if ( (v18 & 0x20000) != 0 )
                        IopCheckInitiatorHint(v15, *(_DWORD *)(a6 + 20), v16, v18);
                    }
                  }
                }
              }
              *(_DWORD *)a1 = v15;
              if ( !*(_BYTE *)(a6 + 82) && !*(_BYTE *)(a6 + 81) )
              {
                if ( (*(_DWORD *)(a6 + 40) & 0x30) != 0 )
                {
                  v20 = *(_DWORD *)(v15 + 44) | 2;
                  *(_DWORD *)(v15 + 44) = v20;
                  if ( (*(_DWORD *)(a6 + 40) & 0x10) != 0 )
                    *(_DWORD *)(v15 + 44) = v20 | 4;
                }
                if ( (*(_DWORD *)(v15 + 44) & 2) != 0 )
                {
                  KeInitializeEvent(v15 + 76, 1, 0);
                  *(_DWORD *)(v15 + 60) = 0;
                  *(_DWORD *)(v15 + 64) = 0;
                  *(_DWORD *)(v15 + 56) = 0;
                }
                if ( (*(_DWORD *)(a6 + 40) & 8) != 0 )
                  *(_DWORD *)(v15 + 44) |= 8u;
                if ( (*(_DWORD *)(a6 + 40) & 2) != 0 )
                  *(_DWORD *)(v15 + 44) |= 0x10u;
                if ( (*(_DWORD *)(a6 + 40) & 4) != 0 )
                  *(_DWORD *)(v15 + 44) |= 0x20u;
                if ( (*(_DWORD *)(a6 + 40) & 0x800) != 0 )
                  *(_DWORD *)(v15 + 44) |= 0x100000u;
                if ( (*(_DWORD *)(a6 + 40) & 0x20000) != 0 )
                  *(_DWORD *)(v15 + 44) |= 0x2000000u;
              }
              JUMPOUT(0x7FA742);
            }
            JUMPOUT(0x7FA72C);
          }
          JUMPOUT(0x7FA6D8);
        }
        JUMPOUT(0x7FA6BE);
      }
      JUMPOUT(0x7FA6BA);
    }
    JUMPOUT(0x7FA65A);
  }
  return sub_7FA648();
}
