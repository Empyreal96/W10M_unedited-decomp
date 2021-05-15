// IoCreateSynchronizationEvent 
 
int __fastcall IoCreateSynchronizationEvent(int a1, int *a2)
{
  int v3; // r4
  int v5; // [sp+8h] [bp-28h]
  int v6[9]; // [sp+Ch] [bp-24h] BYREF

  v6[1] = 24;
  v6[2] = 0;
  v6[3] = a1;
  v6[4] = 640;
  v6[5] = 0;
  v6[6] = 0;
  if ( ZwCreateEvent() < 0 )
    return 0;
  ObReferenceObjectByHandle(v5, 0, ExEventObjectType, 0, (int)v6, 0);
  v3 = v6[0];
  ObfDereferenceObject(v6[0]);
  *a2 = v5;
  return v3;
}
