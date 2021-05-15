// IovAllocateIrp 
 
int __fastcall IovAllocateIrp(int a1, char a2, int a3, int a4)
{
  int v4; // r5
  int v5; // r6
  int v7; // r0
  int *v8; // r8
  int *v9; // r9
  char v10; // r10
  int v11; // r7
  int v12; // r3
  int *v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r2
  int v18; // r3
  int v19; // r4
  int v20; // r0
  int v21; // r3

  v4 = a4;
  v5 = a3;
  v7 = IovpLogStackTrace(0);
  v8 = (int *)v7;
  if ( v7 )
    v9 = (int *)(v7 + 16);
  else
    v9 = 0;
  v10 = a2 + 1;
  v11 = 0;
  v12 = VfIoDisabled;
  __dmb(0xBu);
  if ( !v12 )
  {
    v13 = (int *)ViIrpAllocateLockedPacket(v10, v5, v4);
    if ( v13 )
    {
      v11 = *v13;
      if ( v9 )
      {
        v14 = v9[1];
        v15 = v9[2];
        v16 = v9[3];
        v13[19] = *v9;
        v13[20] = v14;
        v13[21] = v15;
        v13[22] = v16;
        v17 = v9[5];
        v18 = v9[6];
        v19 = v9[7];
        v4 = a4;
        v13[23] = v9[4];
        v13[24] = v17;
        v13[25] = v18;
        v13[26] = v19;
        v5 = a3;
      }
      else
      {
        v13[19] = 0;
      }
      VfIrpDatabaseEntryReleaseLock(v13);
    }
  }
  if ( !v11 )
  {
    v20 = pXdvIoAllocateIrp(a1, v10, v5, v4, IopAllocateIrpPrivate);
    v11 = v20;
    if ( v20 )
      VfIoAllocateIrp2(v20, v9);
  }
  if ( v8 )
    *v8 = v11;
  if ( v11 )
  {
    --*(_BYTE *)(v11 + 35);
    --*(_BYTE *)(v11 + 34);
    v21 = *(_DWORD *)(v11 + 96) - 40;
    *(_DWORD *)(v11 + 96) = v21;
    *(_DWORD *)(v11 + 104) = v21;
    if ( (IopFunctionPointerMask & 4) != 0 && (IopIrpExtensionStatus & 1) != 0 )
      IopInitActivityIdIrp(v11);
  }
  return v11;
}
