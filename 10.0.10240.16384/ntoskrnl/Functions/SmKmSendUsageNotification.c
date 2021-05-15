// SmKmSendUsageNotification 
 
int __fastcall SmKmSendUsageNotification(int a1, _DWORD *a2, int a3)
{
  int v6; // r6
  int v7; // r0
  char v8; // r3
  int v9; // r2
  int result; // r0
  char v11[32]; // [sp+8h] [bp-20h] BYREF

  KeInitializeEvent((int)v11, 0, 0);
  v6 = *(_DWORD *)(a1 + 96);
  v7 = IoGetRelatedDeviceObject(a2);
  *(_BYTE *)(v6 - 40) = 27;
  *(_BYTE *)(v6 - 39) = 22;
  v8 = 1;
  *(_DWORD *)(v6 - 28) = 1;
  if ( a3 )
    v8 = 0;
  *(_BYTE *)(v6 - 32) = v8;
  *(_DWORD *)(v6 - 12) = a2;
  v9 = *(_DWORD *)(a1 + 96);
  *(_DWORD *)(a1 + 24) = -1073741637;
  *(_DWORD *)(v9 - 8) = SmKmGenericCompletion;
  *(_DWORD *)(v9 - 4) = v11;
  *(_BYTE *)(v9 - 37) = -32;
  result = IofCallDriver(v7, a1);
  if ( result == 259 )
  {
    KeWaitForSingleObject((unsigned int)v11, 0, 0, 0, 0);
    result = *(_DWORD *)(a1 + 24);
  }
  return result;
}
