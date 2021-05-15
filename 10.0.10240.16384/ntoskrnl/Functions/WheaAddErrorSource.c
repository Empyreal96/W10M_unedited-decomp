// WheaAddErrorSource 
 
int __fastcall WheaAddErrorSource(int a1, int a2)
{
  int v3; // r3
  int v5; // r5
  int *v6; // r0
  int *v7; // r4
  int v8; // r3
  int (__fastcall *v9)(int, char *, int); // r3

  v3 = *(_DWORD *)(a1 + 8);
  if ( v3 != 5 && v3 != 8 && v3 != 4 )
    return -1073741637;
  v6 = (int *)ExAllocatePoolWithTag(512, 1048, 1634035799);
  v7 = v6;
  if ( !v6 )
    return -1073741670;
  memset(v6, 0, 1048);
  memmove((int)v7 + 73, a1, 0x3CCu);
  v5 = WheapInitializeErrorSource(v7);
  if ( v5 )
  {
    ExFreePoolWithTag((unsigned int)v7);
  }
  else
  {
    v7[10] = a2;
    WheapAddErrorSource(0, v7);
    v5 = 0;
    v8 = (unsigned __int8)WheapInitializationComplete;
    __dmb(0xBu);
    if ( v8 )
    {
      v9 = (int (__fastcall *)(int, char *, int))dword_649F60[7 * *(int *)((char *)v7 + 81)];
      __dmb(0xBu);
      v5 = v9(1, (char *)v7 + 73, a2);
      if ( v5 >= 0 )
        *(int *)((char *)v7 + 85) = 2;
    }
  }
  return v5;
}
