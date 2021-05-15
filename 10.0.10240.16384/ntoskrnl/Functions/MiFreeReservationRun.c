// MiFreeReservationRun 
 
int __fastcall MiFreeReservationRun(int result, unsigned int *a2)
{
  int v3; // r3
  int v4; // r5
  __int64 v5; // r2
  bool v6; // zf

  v3 = a2[1];
  v4 = result;
  if ( v3 )
  {
    do
    {
      result = MiReleasePageFileInfo(v4, *a2, 0, v3);
      v5 = *(_QWORD *)a2;
      v6 = a2[1]-- == 1;
      v3 = ((v5 & 0xFFFFE000) + 0x2000) ^ v5 & 0x1FFF;
      *a2 = v3;
    }
    while ( !v6 );
  }
  return result;
}
