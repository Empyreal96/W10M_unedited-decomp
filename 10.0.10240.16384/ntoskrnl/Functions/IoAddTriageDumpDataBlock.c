// IoAddTriageDumpDataBlock 
 
int __fastcall IoAddTriageDumpDataBlock(int a1, int a2)
{
  int result; // r0
  int v3[4]; // [sp+8h] [bp-10h] BYREF

  v3[0] = IopNumTriageDumpDataBlocks;
  v3[1] = 256;
  v3[2] = (int)&IopTriageDumpDataBlocks;
  result = IopAddTriageDumpDataBlock(1, v3, v3, a1, a2);
  IopNumTriageDumpDataBlocks = v3[0];
  return result;
}
