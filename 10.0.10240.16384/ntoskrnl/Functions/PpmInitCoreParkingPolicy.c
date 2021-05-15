// PpmInitCoreParkingPolicy 
 
int PpmInitCoreParkingPolicy()
{
  unsigned int v0; // r1
  int result; // r0
  char *v2; // r3

  v0 = 0;
  byte_61DC18 = 100;
  result = 100;
  byte_61DCC8 = 100;
  do
  {
    v2 = (char *)&PpmDefaultProfile + v0++;
    v2[122] = 100;
    v2[298] = 100;
    v2[102] = 0;
    v2[278] = 0;
  }
  while ( v0 < 2 );
  byte_61DC0E = 0;
  byte_61DCBE = 0;
  byte_61DC0D = 0;
  byte_61DCBD = 0;
  dword_61DC14 = 1;
  dword_61DCC4 = 1;
  dword_61DC10 = 1;
  dword_61DCC0 = 1;
  byte_61DC09 = 70;
  byte_61DCB9 = 70;
  byte_61DC0A = 97;
  byte_61DCBA = 97;
  byte_61DC0B = 20;
  byte_61DCBB = 20;
  return result;
}
