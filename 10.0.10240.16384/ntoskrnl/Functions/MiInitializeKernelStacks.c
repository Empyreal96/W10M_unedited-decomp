// MiInitializeKernelStacks 
 
unsigned int *MiInitializeKernelStacks()
{
  unsigned int v0; // r9
  unsigned int v1; // r6
  unsigned int v2; // r8
  int v3; // r7
  int v4; // r4
  unsigned int *result; // r0

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_DWORD *)&algn_634841[7] = 0;
  *(_DWORD *)&algn_634841[11] = 0;
  v1 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC40) + 16;
  v2 = ((v1 - KeKernelStackSize) >> 10) & 0x3FFFFC;
  v3 = KfRaiseIrql(2);
  MiMarkBootKernelStack(v2 - 0x40000000, ((v1 >> 10) & 0x3FFFFC) - 0x40000000);
  v4 = ((*(_DWORD *)(v0 + 36) >> 10) & 0x3FFFFC) - 0x40000000;
  MiMarkBootKernelStack(v4, ((*(_DWORD *)(v0 + 40) >> 10) & 0x3FFFFC) - 0x40000000);
  KfLowerIrql(v3);
  MiMarkBootGuardPage((unsigned int *)(v4 - 4));
  result = MiMarkBootGuardPage((unsigned int *)(v2 - 1073741828));
  byte_634840 = (unsigned int)KeKernelStackSize >> 12;
  dword_634860 = (int)MiDeleteNoBlockStacks;
  dword_634864 = 0;
  dword_634858 = 0;
  return result;
}
