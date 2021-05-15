// InitializeListHeadPte 
 
int *__fastcall InitializeListHeadPte(int *result)
{
  int v1; // r2

  result[2] = -1071644672;
  v1 = (int)((((unsigned int)result >> 10) & 0x3FFFFC) - 2097149) >> 2;
  *result = *result & 0xFFF | (v1 << 12);
  result[1] = result[1] & 0xFFF | (v1 << 12);
  return result;
}
