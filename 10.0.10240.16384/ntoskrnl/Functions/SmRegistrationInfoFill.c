// SmRegistrationInfoFill 
 
int __fastcall SmRegistrationInfoFill(int *a1, char a2, int *a3)
{
  int v4; // r4
  int v5; // r3
  int v6; // r0
  int result; // r0
  int v8[4]; // [sp+10h] [bp-10h] BYREF

  v8[0] = 0;
  v4 = ObOpenObjectByPointer(*a1, 0, 0, 2031619, ExEventObjectType, a2, v8);
  if ( v4 < 0 )
  {
    v6 = v8[0];
  }
  else
  {
    v5 = v8[0];
    v6 = 0;
    v8[0] = 0;
    *a3 = v5;
    v4 = 0;
  }
  if ( v6 )
    result = sub_81A2AC();
  else
    result = v4;
  return result;
}
