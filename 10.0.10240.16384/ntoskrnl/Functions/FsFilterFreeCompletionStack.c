// FsFilterFreeCompletionStack 
 
int __fastcall FsFilterFreeCompletionStack(int a1)
{
  char *v1; // r4
  int v3; // r3

  v1 = 0;
  if ( (*(_DWORD *)(a1 + 36) & 2) == 0 )
    return ExFreePoolWithTag(*(_DWORD *)(a1 + 48));
  v3 = *(unsigned __int8 *)(a1 + 4);
  switch ( v3 )
  {
    case 250:
      goto LABEL_10;
    case 251:
      goto LABEL_9;
    case 252:
LABEL_10:
      v1 = &ReleaseOpsEvent;
      break;
    case 253:
LABEL_9:
      v1 = &AcquireOpsEvent;
      break;
    case 254:
      goto LABEL_10;
    case 255:
      goto LABEL_9;
  }
  *(_DWORD *)(*(_DWORD *)(a1 + 48) - 4) = 0;
  return KeSetEvent((int)v1, 0, 0);
}
