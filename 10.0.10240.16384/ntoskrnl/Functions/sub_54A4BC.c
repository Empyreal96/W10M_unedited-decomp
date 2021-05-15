// sub_54A4BC 
 
void sub_54A4BC()
{
  __int16 *v0; // r4
  int v1; // r5
  _QWORD *v2; // r6
  _QWORD *v3; // r9
  __int64 v4; // kr08_8

  do
  {
    if ( *v2 >= *((_QWORD *)v0 + 3) )
      break;
    v4 = *((_QWORD *)v0 + 1);
    if ( *v2 >= v4 )
      JUMPOUT(0x4CF2E8);
    if ( *v3 >= v4 )
      *v3 = v4;
    v0 = (__int16 *)(*((_DWORD *)v0 + 4) - 16);
  }
  while ( *v0 == v1 );
  JUMPOUT(0x4CF2EA);
}
