// PopNotifyDevice 
 
int __fastcall PopNotifyDevice(unsigned __int8 *a1, int a2)
{
  _DWORD *v3; // r6
  int v5; // r2
  int v6; // r8
  int v7; // r9
  int v8; // r1
  int v9; // r6
  unsigned int v10; // r10
  int v11; // r2
  int v12; // r2
  int v13; // r3
  int v14; // r0
  unsigned int v16; // [sp+20h] [bp-28h] BYREF
  int v17[9]; // [sp+24h] [bp-24h] BYREF

  v3 = (_DWORD *)*((_DWORD *)a1 + 8);
  v5 = a1[252] || *v3 != *(_DWORD *)(a2 + 32);
  v6 = PopMapInternalActionToIrpAction(dword_61E848, *((_DWORD *)a1 + 1), v5);
  if ( v6 == 7 && *v3 == *(_DWORD *)(a2 + 32) && *a1 == 2 )
    *v3 = 0;
  v7 = *((_DWORD *)a1 + 1);
  PopAllocateIrp(*(_DWORD *)(a2 + 24), 0, *a1, 0, v7, 1, 0, 0, 0, v17, &v16);
  v10 = v16;
  v9 = v17[0];
  *(_DWORD *)(v16 + 136) = a2;
  *(_BYTE *)(v10 + 140) = 0;
  v11 = *(_DWORD *)(v9 + 96);
  *(_DWORD *)(v11 - 28) = 0;
  *(_DWORD *)(v11 - 24) = v7;
  *(_DWORD *)(v11 - 20) = v6;
  *(_DWORD *)(v11 - 32) = dword_61E844;
  v12 = *(_DWORD *)(v9 + 96);
  *(_DWORD *)(v12 - 8) = PopSystemIrpCompletion;
  *(_DWORD *)(v12 - 4) = v10;
  *(_BYTE *)(v12 - 37) = -32;
  if ( (dword_682610 & 0x8000) != 0 )
    PopLogNotifyDevice(*(int **)(a2 + 24), a2, v9);
  v13 = *a1;
  if ( (v13 == 2 || v13 == 3) && v7 > 1 )
  {
    v14 = IoGetDeviceAttachmentBaseRef(*(_DWORD *)(a2 + 24));
    PoFxActivateDeviceForSystemTransition(v14);
    v13 = 1;
    *(_BYTE *)(v10 + 140) = 1;
  }
  return PopQueueQuerySetIrp(v9, v8, v12, v13);
}
