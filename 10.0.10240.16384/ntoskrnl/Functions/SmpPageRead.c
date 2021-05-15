// SmpPageRead 
 
int __fastcall SmpPageRead(int a1, unsigned int a2, int a3, int *a4)
{
  _DWORD *v4; // lr

  v4 = &SmGlobals[4 * dword_637090];
  ++v4[1684];
  *((_QWORD *)v4 + 841) += 4096i64;
  return SMKM_STORE_MGR<SM_TRAITS>::SmPageRead((int)SmGlobals, a1, a2, a3, a4);
}
