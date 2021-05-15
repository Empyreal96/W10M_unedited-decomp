// PopAllocatePages 
 
const void *__fastcall PopAllocatePages(unsigned int a1)
{
  const void *v1; // r4
  _DWORD *v3; // r0
  int v4; // r7
  int v5; // r2

  v1 = 0;
  if ( (PoDebug & 0x80) != 0 )
    DbgPrint("PopAllocatePages: Enter, requesting %p pages.\r\n", (const void *)a1);
  PopNumberOfPagesForHibernateProcess += a1;
  v3 = PopGenerateMdl(a1);
  v4 = (int)v3;
  if ( !v3 )
    goto LABEL_9;
  if ( (PoDebug & 0x80) != 0 )
    DbgPrint("    Mdl->ByteCount: 0x%x\r\n", v3[5]);
  v1 = (const void *)MmMapLockedPagesSpecifyCache(v4, 0, 1, 0, 1, 1073741856);
  if ( v1 )
  {
    v5 = dword_61EC98;
    if ( *(int *)(dword_61EC98 + 120) >= 0 )
      goto LABEL_11;
  }
  else
  {
LABEL_9:
    v5 = dword_61EC98;
  }
  *(_DWORD *)(v5 + 120) = -1073741670;
LABEL_11:
  if ( (PoDebug & 0x80) != 0 )
    DbgPrint("PopAllocatePages: Returning buffer pointer: %p\r\n", v1);
  return v1;
}
