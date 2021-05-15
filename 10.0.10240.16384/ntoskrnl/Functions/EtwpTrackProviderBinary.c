// EtwpTrackProviderBinary 
 
int __fastcall EtwpTrackProviderBinary(int *a1, int a2, int a3, int a4)
{
  unsigned int v4; // r4
  int v5; // r5
  int v6; // r0
  int v7; // r6
  int v9[6]; // [sp+8h] [bp-18h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  v4 = 0;
  v5 = ObReferenceObjectByHandle(*a1, 2048, EtwpRegistrationObjectType, 1, (int)v9, 0);
  if ( v5 < 0 )
    return v5;
  v6 = KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  v7 = v9[0];
  if ( (*(_BYTE *)(v9[0] + 50) & 0x20) != 0 )
  {
    v5 = 0;
LABEL_7:
    KeReleaseMutex((int)&EtwpNotificationMutex);
    ObfDereferenceObject(v7);
    return v5;
  }
  *(_BYTE *)(v9[0] + 50) |= 0x20u;
  while ( !*(_DWORD *)(*(_DWORD *)(v7 + 16) + v4 + 88) )
  {
    v4 += 32;
    if ( v4 >= 0x100 )
      goto LABEL_7;
  }
  return sub_7EB794(v6);
}
