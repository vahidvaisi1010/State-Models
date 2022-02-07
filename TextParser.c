// Author: Vahid Vaisi
// Just a pesudo

//
typedef int state_t;
typedef int event_t;


struct fsm;

typedef void (*action_t) (struct fsm *);

#define BUFFER_LENGTH 10

// Generic FSM pointer
typedef struct fsm {
  state_t state;  
  size_t nevents; 


  state_t (*transition) (struct fsm *, event_t, action_t *, action_t *);


  char input;
  char buffer[BUFFER_LENGTH];
  size_t length;

  bool final; 


  char next_valid;
  event_t next_event;
} fsm_t;

// Invokes an event handler for a given FSM 
void handle_event (fsm_t *fsm, event_t event); // needs to be implemented

// Valid events for this type of FSM 
typedef enum {
  CHAR_O, CHAR_P, CHAR_S, CHAR_E, CHAR_R, CHAR_C, NIL
} parse_event_t;

fsm_t *parse_init (void);
////////////////////////////////////////////////////////////////
/* Internal type definition of states */
typedef enum { POO, PFP, SP, ER, EC, PC, NST} parse_t;
#define NUM_STATES (NST+1)
#define NUM_EVENTS (NIL+1)

// Prototypes for actions/effects and transition function 
static void accept (fsm_t *);
static void reject (fsm_t *);

// Return an FSM that links to these internals 
fsm_t *
parse_init (void)
{
  fsm_t *fsm = calloc (1, sizeof (fsm_t));
  fsm->nevents = NUM_EVENTS;
  fsm->state = POO;
  fsm->transition = parse_transition;

  /* Set up internal fields for keeping track of characters */
  fsm->input = 0;
  memset (fsm->buffer, 0, sizeof (fsm->buffer));
  fsm->length = 0;

  fsm->next_valid ;
  fsm->next_event ;
  fsm->final;

  return fsm;
}


//
static void
transition_character (fsm_t *fsm)
{
  assert (fsm->length < BUFFER_LENGTH - 1);
  fsm->buffer[fsm->length++] = fsm->input;

  /* Helper inputs to keep track of what the next event will be */
  switch (fsm->input)
    {
    case '':
      fsm->next_valid = '';
      fsm->next_event = CHAR_POO;
      break;
    case '':
      fsm->next_valid = '';
      fsm->next_event = CHAR_PFP;
      break;
    case '':
      fsm->next_valid = '';
      fsm->next_event = CHAR_SP;
      break;
    case '':
      fsm->next_valid = '';
      fsm->next_event = CHAR_ER;
      break;
    case '':
      fsm->next_valid = '';
      fsm->next_event = CHAR_EC;
    break;
    case '':
      fsm->next_valid = '';
      fsm->next_event = CHAR_PC;
    break;

    default:

    }
}

/* Prints that the string is accepted */
static void
accept (fsm_t *fsm)
{

}

/* Prints that the string is rejected and at what character */
static void
reject (fsm_t *fsm)
{

}
//////////////////////////////////////////////////////////////////////////
//int main (int argc, char *argv[])
int main ()
{
    char* c;
    printf("Enter a character\n");
    scanf("%s",c);
    printf("You entered ""%s\n",c);  

  
	for(int i=0;i<k;++i)
		c_arr[i] = arrInt[i] + '0';

  if (argc < 1)
    {
      return 1;
    }

      fsm_t *fsm = parse_init ();

      char *w = c;
      event_t evt = NIL;

      while (*walker != '\0')
        {
          fsm->input = *w;

          if (fsm->input == ' ')
            {
              if (! strcmp (fsm->buffer, "123") || ! strcmp (fsm->buffer, "1234567"))
                evt = SPACE;
              else
                evt = CHAR_other;
            }
          else if (fsm->input == fsm->next_valid)
            evt = fsm->next_event;
          else
            evt = CHAR_other;

          /* The event should never be NIL because of the
             logic above, but this style is for consistency. */
          if (evt != NIL)
            handle_event (fsm, evt);

          /* If a string is accepted or rejected, we are done. */
          if (fsm->final)
            break;

          /* Move to the next input character. */
          walker++;
        }

      /* At the end of the input. Either we have matched exactly
         "int" or "integer", or we have matched a substring (such
         as "inte"). Substrings should be rejected. Use '$' to
         indicate an END-OF-STRING character. */
      if (!fsm->final)
        {
          fsm->input = '$';
          if (! strcmp (fsm->buffer, "123") || ! strcmp (fsm->buffer, "1234567"))
            handle_event (fsm, SPACE);
          else
            handle_event (fsm, CHAR_other);
        }
      printf ("\n");
    //}

  return 0;
}