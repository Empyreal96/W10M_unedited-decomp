// HvpFaultCellWithClustering 
 
void HvpFaultCellWithClustering()
{
  unsigned int v0; // r4
  int v1; // r1
  int v2; // r2
  unsigned int v3; // r1

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v1 = *(_DWORD *)(v0 + 0x3B4);
  v2 = *(unsigned __int8 *)(v0 + 0x3CC);
  *(_BYTE *)(v0 + 972) = 2;
  v3 = v2 + 4 * v1;
  *(_DWORD *)(v0 + 948) = v3 >> 2;
  *(_BYTE *)(v0 + 972) = v3 & 3;
}
