// sub_51F454 
 
void __fastcall sub_51F454(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
  int v16; // r5
  int v17; // r2

  memset(&a11, 0, 24);
  v17 = *(_DWORD *)(v16 + 8);
  a11 = a9;
  a15 = *(_DWORD *)(v16 + 20);
  a16 = 0;
  a13 = a8;
  PpmFireWmiEvent(v17 + 3120, PPM_PERFSTATE_DOMAIN_CHANGE_GUID, 24, &a11);
  JUMPOUT(0x44F4C8);
}
