// PiProcessSetDeviceProblem 
 
int __fastcall PiProcessSetDeviceProblem(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  _DWORD *v5; // r8
  int v6; // r3
  int v7; // r7
  int v8; // r2
  int v9; // r6
  int v10; // r5
  int v11; // r3
  unsigned int v12; // r1
  int v13; // r3
  int v14; // r3
  int v16[6]; // [sp+0h] [bp-18h] BYREF

  v16[0] = a4;
  v4 = 0;
  v5 = *(_DWORD **)(a1 + 20);
  v6 = *(_DWORD *)(*(_DWORD *)(a1 + 8) + 176);
  v16[0] = 0;
  v7 = *(_DWORD *)(v6 + 20);
  v8 = *(_DWORD *)(v7 + 172);
  if ( v8 != 787 && v8 != 788 )
  {
    v9 = 0;
    v10 = 0;
    PiPnpRtlBeginOperation(v16, a2, v8, 787);
    v11 = v5[3];
    if ( (v11 & 0x40000) != 0 )
      v10 = 1;
    if ( (v11 & 0x100) != 0 )
      v10 |= 4u;
    if ( (v11 & 0x8000) != 0 )
      v4 = 0x4000;
    if ( (v11 & 0x400) != 0 )
      v4 |= 0x2000u;
    v12 = v5[4];
    if ( v12 == 14 )
    {
      v13 = *(_DWORD *)(v7 + 172);
      if ( v13 != 770 && v13 != 786 )
        v4 &= 0xFFFFDFFF;
      v10 |= 4u;
    }
    if ( (v4 & 0x6000) != 0 )
    {
      v14 = *(_DWORD *)(v7 + 172);
      if ( v14 != 770 && v14 != 786 || (v4 & 0x4000) == 0 && (v12 >= 0x37 || PipIsProblemReadonly(v7, v12)) )
      {
        v9 = -1073741584;
LABEL_25:
        v4 = v16[0];
        goto LABEL_27;
      }
      PipSetDevNodeProblem(v7, v12, v5[6], v14);
    }
    PipSetDevNodeFlags(v7, v4);
    PipSetDevNodeUserFlags(v7, v10);
    goto LABEL_25;
  }
  v9 = -1073741738;
LABEL_27:
  if ( (v5[5] & 1) != 0 )
    ExFreePoolWithTag((unsigned int)v5);
  if ( v4 )
    PiPnpRtlEndOperation(v4);
  return v9;
}
