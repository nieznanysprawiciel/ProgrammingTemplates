#include "ThirdPersonBobaFett.h"
#include "StateMachine.h"

StateMachine::StateMachine()
{
	current_state_num = 0;
	current_state = nullptr;
}

StateMachine::~StateMachine()
{
	for ( auto State : states )
		delete State.second;
}

/**@brief Ustawia pocz�tkowy stan maszyny.

Podany stan jest dodawany do maszyny i jednocze�nie ustawiany jako pocz�tkowy.
Funkcja musi zosta� koniecznie wywo�ana inaczej maszyna nie b�dzie dzia�a� poprawnie.
*/
void StateMachine::addInitState( State* new_state )
{
	addState( new_state );
	current_state = new_state;
	current_state_num = new_state->getId();
}


int StateMachine::input( const char* event_id, float value )
{
	int new_state_id = current_state->transition( event_id, value );
	if( new_state_id != current_state_num )
	{
		auto new_state_iter = states.find( new_state_id );
		if( new_state_iter != states.end() )
		{
			current_state->stateEnd();
			
			current_state = (*new_state_iter).second;
			current_state_num = new_state_id;
			
			current_state->stateBegin();
		}
	}
	return current_state_num;
}	

void StateMachine::addState( State* new_state )
{
	int new_id = new_state->getId();
	states.insert( std::make_pair( new_id, new_state ) );
}