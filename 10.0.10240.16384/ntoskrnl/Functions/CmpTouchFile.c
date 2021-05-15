// CmpTouchFile 
 
int CmpTouchFile()
{
  int v0; // r4
  int v1; // r5
  int v2; // r0
  int v4; // [sp+1Ch] [bp-2Ch] BYREF
  int v5[4]; // [sp+20h] [bp-28h] BYREF

  v4 = 0;
  v5[0] = 0;
  v5[2] = 0;
  v5[3] = 0;
  v0 = CmpCreateEvent(1, &v4, v5);
  v1 = v5[0];
  if ( v0 >= 0 )
  {
    v2 = ZwReadFile();
    v0 = v2;
    if ( v2 == 259 )
      return sub_7EB28C();
    if ( v2 >= 0 )
      v0 = 0;
  }
  if ( v1 )
    ObfDereferenceObject(v1);
  if ( v4 )
    ZwClose();
  return v0;
}
