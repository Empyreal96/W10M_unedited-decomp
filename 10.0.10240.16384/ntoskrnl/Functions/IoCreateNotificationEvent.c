// IoCreateNotificationEvent 
 
int __fastcall IoCreateNotificationEvent(int a1, _DWORD *a2)
{
  int v3; // r0
  int v4; // r4
  int v6; // [sp+8h] [bp-28h]
  int v7[9]; // [sp+Ch] [bp-24h] BYREF

  v7[1] = 24;
  v7[2] = 0;
  v7[3] = a1;
  v7[4] = 640;
  v7[5] = 0;
  v7[6] = 0;
  if ( ZwCreateEvent() < 0 )
    return 0;
  v3 = ObReferenceObjectByHandle(v6, 0, ExEventObjectType, 0, v7);
  v4 = v7[0];
  if ( v3 < 0 )
    v4 = 0;
  else
    ObfDereferenceObject(v7[0]);
  *a2 = v6;
  return v4;
}
