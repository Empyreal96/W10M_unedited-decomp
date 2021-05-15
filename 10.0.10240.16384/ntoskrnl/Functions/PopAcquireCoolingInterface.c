// PopAcquireCoolingInterface 
 
int __fastcall PopAcquireCoolingInterface(int a1)
{
  int v2; // r0
  int v3; // r5
  int v4; // r2
  int v5; // r4

  v2 = IoAllocateIrp(*(_BYTE *)(*(_DWORD *)(a1 + 24) + 48), 0);
  v3 = v2;
  if ( !v2 )
    return -1073741670;
  v4 = *(_DWORD *)(v2 + 96);
  *(_BYTE *)(v4 - 40) = 27;
  *(_BYTE *)(v4 - 39) = 8;
  *(_DWORD *)(v4 - 32) = &GUID_THERMAL_COOLING_INTERFACE;
  *(_WORD *)(v4 - 28) = 28;
  *(_WORD *)(v4 - 26) = 1;
  *(_DWORD *)(v4 - 24) = a1 + 44;
  *(_DWORD *)(v4 - 20) = 0;
  *(_DWORD *)(v2 + 24) = -1073741637;
  v5 = IoSynchronousCallDriver(*(_DWORD *)(a1 + 24), v2);
  IoFreeIrp(v3);
  return v5;
}
