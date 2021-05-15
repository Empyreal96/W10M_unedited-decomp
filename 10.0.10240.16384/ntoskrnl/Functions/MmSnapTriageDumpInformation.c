// MmSnapTriageDumpInformation 
 
int __fastcall MmSnapTriageDumpInformation(int a1, unsigned int *a2)
{
  int v4; // r3
  int v5; // r3
  int v6; // r5
  unsigned int v7; // t1
  __int16 *v8; // r4
  int v9; // r5
  int v10; // t1

  memset(&MiTriageDumpData, 0, 40);
  MiTriageDumpData = dword_640080;
  v4 = dword_63441C;
  __dmb(0xBu);
  dword_620D44 = v4;
  v5 = dword_634418;
  __dmb(0xBu);
  dword_620D48 = v5;
  dword_620D4C = dword_634420;
  dword_620D50 = dword_634424;
  dword_620D54 = dword_634410;
  dword_620D58 = KeFeatureBits;
  dword_620D5C = 0;
  v6 = 4;
  dword_620D60 = MEMORY[0xFFFF9240];
  do
  {
    v7 = *a2++;
    MiAddTriageDumpPtes(v7);
    --v6;
  }
  while ( v6 );
  v8 = &IopRunTimeContextOffsets;
  v9 = 15;
  do
  {
    v10 = (unsigned __int16)*v8++;
    MiAddTriageDumpPtes(*(_DWORD *)(v10 + a1));
    --v9;
  }
  while ( v9 );
  return IoAddTriageDumpDataBlock((int)&MiTriageDumpData, 40);
}
