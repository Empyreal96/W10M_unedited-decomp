// SmCreateEvent 
 
int __fastcall SmCreateEvent(int a1, _DWORD *a2)
{
  int v3; // r4
  int v4; // r0
  int v6[11]; // [sp+Ch] [bp-2Ch] BYREF

  v6[1] = 24;
  v6[2] = 0;
  v6[4] = 512;
  v6[3] = 0;
  v6[5] = 0;
  v6[6] = 0;
  v3 = ZwCreateEvent();
  if ( v3 >= 0 )
  {
    v3 = ObReferenceObjectByHandle(0, 2031619, ExEventObjectType, 0, (int)v6, 0);
    v4 = v6[0];
    if ( v3 >= 0 )
    {
      *a2 = v6[0];
      v4 = 0;
      v3 = 0;
    }
    if ( v4 )
      ObfDereferenceObject(v4);
  }
  return v3;
}
