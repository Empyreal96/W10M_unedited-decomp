// _CmDeleteDeviceMappedPropertyForAllDriverKeyRegValues 
 
int __fastcall CmDeleteDeviceMappedPropertyForAllDriverKeyRegValues(int a1, int a2)
{
  int *v2; // r4
  int v5; // r5
  int v6; // t1

  v2 = (int *)&off_8C97B0;
  v5 = 13;
  do
  {
    v6 = *v2;
    v2 += 4;
    PnpSetObjectProperty(a1, a2, 1, 0, 0, v6, 0, 0, 0, 0);
    --v5;
  }
  while ( v5 );
  return 0;
}
