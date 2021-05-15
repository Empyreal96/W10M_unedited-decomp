// MiFillGapAddresses 
 
int __fastcall MiFillGapAddresses(__int64 a1)
{
  char *v1; // r4
  int v2; // r2
  char v4; // [sp+8h] [bp-20h] BYREF

  v1 = &v4;
  v2 = 2;
  do
  {
    LODWORD(a1) = (((unsigned int)a1 >> 10) & 0x3FFFFC) - 0x40000000;
    HIDWORD(a1) = ((HIDWORD(a1) >> 10) & 0x3FFFFC) - 0x40000000;
    *(_QWORD *)v1 = a1;
    v1 += 8;
    --v2;
  }
  while ( v2 );
  return MiFillGapPtes(a1);
}
