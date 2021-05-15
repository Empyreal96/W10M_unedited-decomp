// SmRegistrationCtxStart 
 
int __fastcall SmRegistrationCtxStart(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r0
  int v8[4]; // [sp+0h] [bp-10h] BYREF

  v8[1] = a4;
  v8[0] = 0;
  v5 = SmCreateEvent(a1, v8);
  if ( v5 < 0 )
  {
    v6 = v8[0];
  }
  else
  {
    v6 = 0;
    v5 = 0;
    *a1 = v8[0];
  }
  if ( v6 )
    ObfDereferenceObject(v6);
  return v5;
}
