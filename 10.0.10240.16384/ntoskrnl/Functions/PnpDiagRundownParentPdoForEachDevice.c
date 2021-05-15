// PnpDiagRundownParentPdoForEachDevice 
 
int __fastcall PnpDiagRundownParentPdoForEachDevice(int a1)
{
  int v1; // r3
  int v2; // r3
  int v4[14]; // [sp+8h] [bp-38h] BYREF

  if ( !*(_DWORD *)(a1 + 40) )
  {
    v4[2] = a1 + 16;
    v4[3] = 0;
    v4[4] = 4;
    v4[5] = 0;
    v1 = *(_DWORD *)(a1 + 8);
    if ( v1 )
      v2 = *(_DWORD *)(v1 + 16);
    else
      v2 = 0;
    v4[0] = v2;
    v4[6] = (int)v4;
    v4[7] = 0;
    v4[8] = 4;
    v4[9] = 0;
    EtwWrite(PnpRundownEtwHandle, unk_649E8C, (int)KMPnPRundownEvt_SleepStudy_ParentPdo, 0);
  }
  return 0;
}
