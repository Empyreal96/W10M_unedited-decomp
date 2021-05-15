// sub_7C8900 
 
void __fastcall sub_7C8900(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)
{
  unsigned int v11; // r5
  int v12; // r8
  int (**v13)[5]; // r7
  int v14; // r4
  unsigned int v15; // r1
  int (*v16)[5]; // t1

  v12 = *(_DWORD *)(v11 + 16);
  v13 = &off_8C9408;
  v14 = 0;
  while ( 1 )
  {
    v16 = *v13;
    v13 += 2;
    v15 = (unsigned int)v16;
    if ( v12 == (*v16)[4] && !memcmp(v11, v15, 16) )
      break;
    if ( ++v14 )
      goto LABEL_6;
  }
  CmGetInterfaceClassMappedPropertyFromComposite(a11, a10, a9, v11);
LABEL_6:
  JUMPOUT(0x6CE1BC);
}
